using UnityEngine;
/*
 * Two functions to active the animation for when the player wins or loses.
 */
public class gameManager : MonoBehaviour
{
    /*
     * Four GameObjects which are basically classes to use functions
     * from these classes
     */
    [SerializeField] private int lvl;
    [SerializeField] private GameObject gameOverUI;
    [SerializeField] private GameObject wonRoundUI;
    [SerializeField] private GameObject joystick;
    [SerializeField] private GameObject shootbutton;
    /*
     * Boolean variables to enable the animation for player.
     * Booleans are needed so that the functions are not running continuously.
     */
    bool gameHasEnded = false;
    bool winRound = false;
    //  gameOver() turns off player UI and turns on lost animation
    public void gameOver()
    {
        if (gameHasEnded == false)
        {
            gameHasEnded = true;
            joystick.SetActive(false);
            shootbutton.SetActive(false);
            gameOverUI.SetActive(true);
        }
    }
    // gameWon() turns off player UI and turns on won animation
    public void gameWon()
    {
        if (winRound == false)
        {
            if (lvl > PlayerPrefs.GetInt("levels"))
            {
                PlayerPrefs.SetInt("levels", lvl);
                PlayerPrefs.SetInt("levelsBeaten", (lvl));
            }
            winRound = true;
            joystick.SetActive(false);
            shootbutton.SetActive(false);
            wonRoundUI.SetActive(true);
        }
    }
}
