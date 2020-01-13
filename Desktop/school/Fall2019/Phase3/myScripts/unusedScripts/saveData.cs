using UnityEngine;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

public static class saveData
{
   /* // Start is called before the first frame update
    public static void saveGame(SwitchScenes levelCurrent)
    {
        BinaryFormatter formatter = new BinaryFormatter();
        string path = Application.persistentDataPath + "/gameData.dat";
//        FileStream stream = new FileStream(file, FileMode.Create);

        gameData data = new gameData(levelCurrent);
        using (var file = File.Open(path, FileMode.OpenOrCreate))
        {
            formatter.Serialize(file, data);
        }
        //stream.Close();
    }

    public static gameData loadGame()
    {
        string file = Application.persistentDataPath + "gameData.dat";
        if (File.Exists(file))
        {
            BinaryFormatter formatter = new BinaryFormatter();
            FileStream stream = new FileStream(file, FileMode.Open);
            gameData data = formatter.Deserialize(stream) as gameData;
            stream.Close();
            return data;
        }
        else
        {
            Debug.LogError("Save file is not found in " + file);
            return null;
        }
    }*/
}
