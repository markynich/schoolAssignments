using UnityEngine;
using UnityEngine.SceneManagement;
/*
 *  After player has lost or won.
 *  He/she will be sent back to Menu Selection.
 */
public class backToMenu : MonoBehaviour
{
    public void backtoMenu()
    {
        SceneManager.LoadScene(1);
    }
}
