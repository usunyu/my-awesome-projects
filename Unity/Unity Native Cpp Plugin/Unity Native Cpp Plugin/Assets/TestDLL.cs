using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class TestDLL : MonoBehaviour
{
    // The imported function
    [DllImport("TestNativePluginDLL", EntryPoint = "TestSort")]
    public static extern void TestSort(int[] a, int length);

    private int[] arr = new int[] { 9, 3, 4, 5, 2, 4, 6 };

    void Start()
    {
        Debug.Log("Initial Array:");
        foreach (int i in arr)
        {
            Debug.Log(i);
        }
        TestSort(arr, arr.Length);
        Debug.Log("Use Native Plugin to Sort:");
        foreach (int i in arr)
        {
            Debug.Log(i);
        }
    }
}