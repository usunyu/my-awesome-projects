using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections;
using System.Runtime.InteropServices;

public class SampleCode : MonoBehaviour {

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern int Add(int a, int b);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern void CallMe(Action<int> action);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern IntPtr CreateSharedAPI(int id);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern int GetMyIdPlusTen(IntPtr api);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern void DeleteSharedAPI(IntPtr api);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern IntPtr GetArray(IntPtr api);

    [DllImport("CSharp-Marshaling-Xcode")]
    static extern void DeleteArray(IntPtr myArray); 

    Text text;
    IntPtr sharedAPI;
    string myStuff;
	// Use this for initialization
	void Start () {
        text = GetComponent<Text>();
        CallMe(IWasCalled);
        sharedAPI = CreateSharedAPI(11);

        myStuff = "";
        IntPtr array = GetArray(sharedAPI);
        //unsafe
        //{
        //    int** myArray = (int**)array.ToPointer();
        //    for (int i = 0; i < 10; i++) {
        //        for (int j = 0; j < 10; j++) {
        //            myStuff += myArray[i][j].ToString();
        //        }
        //    }
        //}
        text.text = myStuff;
    }

    void IWasCalled(int value) {
        //throw new NotImplementedException();
        text.text = value.ToString();
    }
	
	// Update is called once per frame
	void Update () {
        //text.text = "Hello World";
        //text.text = Add(1, 3).ToString();
        //text.text = GetMyIdPlusTen(sharedAPI).ToString();
	}

    void OnDestory() {
        DeleteSharedAPI(sharedAPI);
    }
}
