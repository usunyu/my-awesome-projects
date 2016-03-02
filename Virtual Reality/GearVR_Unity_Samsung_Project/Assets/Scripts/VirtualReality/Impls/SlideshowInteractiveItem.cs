using UnityEngine;
using VirtualReality.Utils;

namespace VirtualReality.Impls {
	
	// This script is a simple example of how an interactive item can
	// be used to change things on gameobjects by handling events.
	public class SlideshowInteractiveItem : MonoBehaviour {

		[SerializeField] private Material m_NormalMaterial;                
		[SerializeField] private Material m_OverMaterial;                  
		[SerializeField] private Material m_ClickedMaterial;               
		[SerializeField] private Material m_DoubleClickedMaterial;         
		[SerializeField] private VRInteractiveItem m_InteractiveItem;
		[SerializeField] private Renderer m_Renderer;

		// Public control that forces the button type (increment/decrement/slideshow) to set the
		// texture cycler mode. If set to false, textures will cycle according to how the texture
		// cycler is configured in the editor.
		public bool ButtonsDefineCyclerMode = true;
		public GameObject[] TextureObject = new GameObject[1];


		private void Awake ()
		{
			m_Renderer.material = m_NormalMaterial;
		}


		private void OnEnable()
		{
			m_InteractiveItem.OnOver += HandleOver;
			m_InteractiveItem.OnOut += HandleOut;
			m_InteractiveItem.OnClick += HandleClick;
			m_InteractiveItem.OnDoubleClick += HandleDoubleClick;
		}


		private void OnDisable()
		{
			m_InteractiveItem.OnOver -= HandleOver;
			m_InteractiveItem.OnOut -= HandleOut;
			m_InteractiveItem.OnClick -= HandleClick;
			m_InteractiveItem.OnDoubleClick -= HandleDoubleClick;
		}


		//Handle the Over event
		private void HandleOver()
		{
			Debug.Log("Show over state");
			m_Renderer.material = m_OverMaterial;
		}


		//Handle the Out event
		private void HandleOut()
		{
			Debug.Log("Show out state");
			m_Renderer.material = m_NormalMaterial;
		}


		//Handle the Click event
		private void HandleClick()
		{
			Debug.Log("Show click state");
			m_Renderer.material = m_ClickedMaterial;

			for(int i = 0; i < TextureObject.Length; ++i) {
				TextureCycler objToCycleCycler = TextureObject[i].GetComponent<TextureCycler>();

				// Cycle the textures on it!
				if(objToCycleCycler != null) {
					if(ButtonsDefineCyclerMode) {
						objToCycleCycler.setTextureCycleMode(0);
					}

					objToCycleCycler.cycleTextures();
				}
			}
		}


		//Handle the DoubleClick event
		private void HandleDoubleClick()
		{
			Debug.Log("Show double click");
			m_Renderer.material = m_DoubleClickedMaterial;
		}
	}
}