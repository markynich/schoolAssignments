using UnityEngine;
using UnityEngine.SceneManagement;
/*
 * Script for Main Menu, to add functionality to buttons
 */
public class MainMenu : MonoBehaviour
{
    [SerializeField] private GameObject loadButton;

    private void Start()
    {
        if (PlayerPrefs.GetInt("levels") >= 1)
        {
            loadButton.SetActive(true);
        }
    }
    //For Button(Quit): Quits the game
    //However, unable to debug as I need to create game into iOS
    public void QuitGame ()
    {
        Debug.Log("Quit");
        Application.Quit();
    }
    public void newGame()
    {
        PlayerPrefs.SetInt("levels", 0);
        PlayerPrefs.SetInt("levelsBeaten", 0);
        SceneManager.LoadScene(1);
    }
    public void loadGame()
    {
        SceneManager.LoadScene(1);
    }
}
