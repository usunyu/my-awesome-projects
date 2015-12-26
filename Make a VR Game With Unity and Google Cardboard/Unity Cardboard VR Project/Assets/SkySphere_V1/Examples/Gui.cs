using UnityEngine;
using System.Collections;

public class Gui : MonoBehaviour {
	
	public Material[] mats;
	public GameObject[] models;
	private bool toggle=false;
	private int currentSky;
	
	void OnGUI(){
		
		GUI.color = new Color(1f,1f,1f);
		GUI.Label( new Rect(Screen.width/2-75,10,200,30),"Skysphere : " + mats[currentSky].name);
		toggle = GUI.Toggle( new Rect(Screen.width/2-50,Screen.height-30,200,30),toggle,"Toogle buttons");
		
		
		if (toggle){
			for (int i=0;i<mats.Length/2;i++){
			
				GUI.color = new Color(1f,0.75f,0.5f);
				if (GUI.Button(new Rect( 10,10+i*30,110,20),mats[i].name)){
					currentSky=i;
					ApplyMaterial();
				}
			}
			
			int j=0;
			for (int i=mats.Length/2;i<mats.Length;i++){
				GUI.color = new Color(1f,0.75f,0.5f);
				if (GUI.Button(new Rect( Screen.width-120,10+j*30,110,20),mats[i].name)){
					currentSky=i;
					ApplyMaterial();
				}
				j++;
			}
		}
		else{
			if (GUI.Button( new Rect( 5,5,50,30), "Prev")){
				currentSky--;
				if (currentSky<0){
					currentSky = mats.Length-1;
				}
				ApplyMaterial();
			}
			
			if (GUI.Button( new Rect( Screen.width-55,5,50,30), "Next")){
				currentSky++;
				if (currentSky>mats.Length-1){
					currentSky = 0;
				}
				ApplyMaterial();
			}
		}
		
		
	}
	
	void ApplyMaterial(){
		for (int g=0;g<models.Length;g++){
			models[g].GetComponent<Renderer>().material = mats[currentSky];	
		}
	}
}
