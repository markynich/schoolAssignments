using UnityEngine;

public class EnemySpawn : MonoBehaviour
{
    /*
     * Objects to reference location for zombie mickeys to spawn
     * mickPreFab is game object to reference to spawn character.
     */
    [SerializeField] private GameObject mickPreFab;
    [SerializeField] private Transform[] EnemySpawnPoint;

    private int counter = 0; //counter to know how many monsters have been spawned
    [SerializeField] private int countMax;    //control how many monsters will be spawned
    /*
     * function spawnWave() is referenced to ZombieMickey class to be called
     * every time a mickey is spawned to consisently spawn the monster every 4
     * seconds until the counter == countMax
     */
    public void spawnWave()
    {
        Invoke("Respawn", 4);
    }
    /*
     * Spawns enemy and keeps spawning enemy until counter == max
     * creates a random number form 0-20
     * spawn left side if number <=9 & spawn right side if number >= 10
     */
    public void Spawn(int spawnPoint) //Respawn enemy
    {
            GameObject enemyClone = (GameObject)Instantiate(mickPreFab,
                              EnemySpawnPoint[spawnPoint].position, EnemySpawnPoint[spawnPoint].rotation);
            enemyClone.GetComponent<SpriteRenderer>().color = new Color(1f, 1f, 1f, 1f);
            enemyClone.SetActive(true);
    }
}
