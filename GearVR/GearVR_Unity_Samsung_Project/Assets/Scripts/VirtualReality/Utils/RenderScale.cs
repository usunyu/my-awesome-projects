using UnityEngine;
using UnityEngine.VR;

namespace VirtualReality.Utils {
	
	// This script shows how renderscale affects the visuals
	// and performance of a scene.
	public class RenderScale : MonoBehaviour {

		//The render scale. Higher numbers = better quality, but trades performance
		[SerializeField] private float m_RenderScale = 1.5f;


		void Start () {
			VRSettings.renderScale = m_RenderScale;
		}
	}
}