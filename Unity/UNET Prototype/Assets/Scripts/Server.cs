using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;

public class ServerClient {
    public int connectionID;
    public string playerName;

    public Vector3 position;
}

public class Server : MonoBehaviour {

    private const int MAX_CONNECTION = 100;

    private int port = 8088;

    private int hostID;
    private int webHostID;

    private int reliableChannel;
    private int unreliableChannel;

    private bool isStarted = false;
    private byte error;

    private List<ServerClient> clients = new List<ServerClient>();

    private float lastMovementUpdate;
    private float movementUpdateRate = 0.05f;

    private void Start() {
        Application.runInBackground = true;

        NetworkTransport.Init();
        ConnectionConfig config = new ConnectionConfig();

        reliableChannel = config.AddChannel(QosType.Reliable);
        unreliableChannel = config.AddChannel(QosType.Unreliable);

        HostTopology topology = new HostTopology(config, MAX_CONNECTION);

        hostID = NetworkTransport.AddHost(topology, port, null);
        webHostID = NetworkTransport.AddWebsocketHost(topology, port, null);

        isStarted = true;
    }

    void Update() {
        if (!isStarted)
            return;

        int recHostId;
        int connectionId;
        int channelId;
        byte[] recBuffer = new byte[1024];
        int bufferSize = 1024;
        int dataSize;

        NetworkEventType recData = NetworkTransport.Receive(
            out recHostId,
            out connectionId,
            out channelId,
            recBuffer,
            bufferSize,
            out dataSize,
            out error);

        switch (recData) {
            case NetworkEventType.Nothing:         //1
                break;
            case NetworkEventType.ConnectEvent:    //2
                Debug.Log("Player " + connectionId + " has connected");
                OnConnection(connectionId);
                break;
            case NetworkEventType.DataEvent:       //3
                string msg = Encoding.Unicode.GetString(recBuffer, 0, dataSize);
                Debug.Log("Receiving from " + connectionId + " : " + msg);
                string[] splitData = msg.Split('|');
                switch (splitData[0]) {
                    case "NAMEIS":
                        OnNameIs(connectionId, splitData[1]);
                        break;
                    case "MYPOSITION":
                        string[] d = splitData[1].Split('%');
                        OnMyPosition(connectionId, float.Parse(d[0]), float.Parse(d[1]));
                        break;
                    case "DC":

                        break;
                    default:
                        Debug.Log("Invalid message: " + msg);
                        break;
                }
                break;
            case NetworkEventType.DisconnectEvent: //4
                Debug.Log("Player " + connectionId + " has disconnected");
                OnDisconnection(connectionId);
                break;
        }

        // Ask player for their position
        if (Time.time - lastMovementUpdate > movementUpdateRate) {
            lastMovementUpdate = Time.time;
            string m = "ASKPOSITION|";
            foreach (ServerClient sc in clients) {
                m += (sc.connectionID.ToString() + '%' + sc.position.x.ToString() + '%' + sc.position.y.ToString() + '|');
            }
            m.Trim('|');
            Send(m, unreliableChannel, clients);
        }
    }

    private void OnConnection(int connID) {
        // When the player joins the server, tell him his ID
        // Request his name and send the name of all other players
        string msg = "ASKNAME|" + connID + "|";
        foreach (ServerClient sc in clients) {
            msg += sc.playerName + '%' + sc.connectionID + '|';
        }
        msg.Trim('|');

        // Add him to a list
        ServerClient c = new ServerClient();
        c.connectionID = connID;
        c.playerName = "TEMP";
        clients.Add(c);

        // ASKNAME|3|DAVE%1|MICHAEL%2|TEMP%3
        Send(msg, reliableChannel, connID);
    }

    private void OnDisconnection(int connID) {
        // Remove this player from our client list
        clients.Remove(clients.Find((x) => x.connectionID == connID));

        // Tell everyone that somebody else has disconnected
        Send("DC|" + connID, reliableChannel, clients);
    }

    private void OnNameIs(int cnnID, string playerName) {
        // Link the name to connection ID
        clients.Find(x => x.connectionID == cnnID).playerName = playerName;
        // Tell everybody that a new player has connected
        Send("CNN|" + playerName + '|' + cnnID, reliableChannel, clients);
    }

    private void OnMyPosition(int cnnID, float x, float y) {
        clients.Find(obj => obj.connectionID == cnnID).position = new Vector3(x, y, 0);
    }

    private void Send(string message, int channelID, int connID) {
        List<ServerClient> c = new List<ServerClient>();
        c.Add(clients.Find(x => x.connectionID == connID));
        Send(message, channelID, c);
    }

    private void Send(string message, int channelID, List<ServerClient> c) {
        Debug.Log("Sending: " + message);
        byte[] msg = Encoding.Unicode.GetBytes(message);
        foreach (ServerClient sc in c) {
            NetworkTransport.Send(hostID, sc.connectionID, channelID, msg, message.Length * sizeof(char), out error);

        }
    }
}
