using UnityEngine;
using UnityEngine.SceneManagement;
using System.Runtime.Serialization.Formatters.Binary;
/*
 * Script is for menu Selection.
 * As game scenes increases, this script will increase
 */
public class SwitchScenes : MonoBehaviour
{
    public GameObject[] scenes;
    public GameObject[] scenesBeaten;
    //Load Main Menu

    private void Update()
    {
        LoadUnlockedLvls();
    }
    public void backToMainMenu()
    {
        SceneManager.LoadScene(0);
    }
    //Load Level 1 of Main Street
    public void LevelLoader(int choice)
    {
        SceneManager.LoadScene(choice);
    }
    /*public void saveGame()
    {
        saveData.saveGame(this);
    }
    */
    public void LoadUnlockedLvls()
    {
        for (int i = 1; i <= PlayerPrefs.GetInt("levels"); i++)
        {
            scenes[i].SetActive(true);
        }
        for (int j = 0; j < PlayerPrefs.GetInt("levelsBeaten"); j++)
        {
            scenesBeaten[j].SetActive(true);
            scenes[j].SetActive(false);
        }

    }
}
