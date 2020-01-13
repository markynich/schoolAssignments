using UnityEngine;
using UnityEngine.SceneManagement;

public class tempScript : MonoBehaviour
{
    // Start is called before the first frame update
    public void pressButton(int lvl)
    {
        if (lvl > PlayerPrefs.GetInt("levels"))
        {
            PlayerPrefs.SetInt("levels", lvl);
            PlayerPrefs.SetInt("levelsBeaten", (lvl));
        }
        SceneManager.LoadScene(1);
    }
}
