using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    [SerializeField]
    private string ARKitScene;

    [SerializeField]
    private string ARCoreScene;

    private void Start()
    {
        TryLoadMainScene();
    }

    private void TryLoadMainScene()
    {
        string sceneToLoad = "";
#if UNITY_IOS
        sceneToLoad = ARKitScene;
#elif UNITY_ANDROID
        sceneToLoad = ARCoreScene;
#endif

        if (sceneToLoad == "")
        {
            Debug.LogError("Can't load main scene");

            return;
        }

        SceneManager.LoadScene(sceneToLoad);
    }
}
