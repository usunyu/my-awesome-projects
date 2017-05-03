using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;

public class Player {
    public string playerName;
    public GameObject avatar;
    public int connectionID;
}

public class Client : MonoBehaviour {

    private const int MAX_CONNECTION = 100;

    private int port = 8088;

    private int hostID;
    private int webHostID;

    private int reliableChannel;
    private int unreliableChannel;

    private int ourClientID;
    private int connectionID;

    private float connectionTime;
    private bool isConnected = false;
    private bool isStarted = false;
    private byte error;

    private string playerName;
    public GameObject playerPrefab;
    public Dictionary<int, Player> players = new Dictionary<int, Player>();

    public void Connect() {
        // Does the player have a name?
        string pName = GameObject.Find("NameInput").GetComponent<InputField>().text;
        if (pName == "") {
            Debug.Log("You must enter a name!");
            return;
        }

        playerName = pName;

        NetworkTransport.Init();
        ConnectionConfig config = new ConnectionConfig();

        reliableChannel = config.AddChannel(QosType.Reliable);
        unreliableChannel = config.AddChannel(QosType.Unreliable);

        HostTopology topology = new HostTopology(config, MAX_CONNECTION);

        hostID = NetworkTransport.AddHost(topology);
        connectionID = NetworkTransport.Connect(hostID, "0.0.0.0", port, 0, out error);

        connectionTime = Time.time;
        isConnected = true;
    }

    private void Update() {
        if (!isConnected)
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
            case NetworkEventType.DataEvent:
                string msg = Encoding.Unicode.GetString(recBuffer, 0, dataSize);
                Debug.Log("Receiving: " + msg);
                string[] splitData = msg.Split('|');
                switch (splitData[0]) {
                    case "ASKNAME":
                        OnAskName(splitData);
                        break;
                    case "CNN":
                        SpawnPlayer(splitData[1], int.Parse(splitData[2]));
                        break;
                    case "DC":
                        PlayerDisconnected(int.Parse(splitData[1]));
                        break;
                    case "ASKPOSITION":
                        OnAskPosition(splitData);
                        break;
                    default:
                        Debug.Log("Invalid message: " + msg);
                        break;
                }
                break;
        }
    }

    private void OnAskName(string[] data) {
        // Set this client's ID
        ourClientID = int.Parse(data[1]);

        // Send our name to the server
        Send("NAMEIS|" + playerName, reliableChannel);
        // Create all the other players
        for (int i = 2; i < data.Length - 1; i++) {
            string[] d = data[i].Split('%');
            SpawnPlayer(d[0], int.Parse(d[1]));
        }
    }

    private void OnAskPosition(string[] data) {
        if (!isStarted)
            return;

        // Update everyone else
        for (int i = 1; i < data.Length - 1; i++) {
            string[] d = data[i].Split('%');

            // Prevent the server updating us
            if (ourClientID != int.Parse(d[0])) {
                Vector3 position = Vector3.zero;
                position.x = float.Parse(d[1]);
                position.y = float.Parse(d[2]);
                players[int.Parse(d[0])].avatar.transform.position = position;
            }
        }

        // Send our own position
        Vector3 myPosition = players[ourClientID].avatar.transform.position;
        string m = "MYPOSITION|" + myPosition.x.ToString() + '%' + myPosition.y.ToString();
        Send(m, unreliableChannel);
    }

    private void SpawnPlayer(string playerName, int cnnID) {
        GameObject go = Instantiate(playerPrefab) as GameObject;

        // Is this ours?
        if (cnnID == ourClientID) {
            // Add mobility
            go.AddComponent<PlayerMotor>();
            if (GameObject.Find("Canvas") != null)
                GameObject.Find("Canvas").SetActive(false);
            isStarted = true;
        }

        Player p = new Player();
        p.avatar = go;
        p.playerName = playerName;
        p.connectionID = cnnID;
        p.avatar.GetComponentInChildren<TextMesh>().text = playerName;
        Debug.Log("Add cnnID: " + cnnID);
        players.Add(cnnID, p);
    }

    private void PlayerDisconnected(int cnnID) {
        Destroy(players[cnnID].avatar);
        players.Remove(cnnID);
    }

    private void Send(string message, int channelID) {
        Debug.Log("Sending: " + message);
        byte[] msg = Encoding.Unicode.GetBytes(message);
        NetworkTransport.Send(hostID, connectionID, channelID, msg, message.Length * sizeof(char), out error);
    }
}
