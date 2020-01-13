using UnityEngine;
/*
 * Scripts controls the spawn rate and enemies spawning into the map
 */
public class Enemy : MonoBehaviour
{
    /*
     * Objects to reference location for zombie mickeys to spawn
     * mickPreFab is game object to reference to spawn mickey.
     */
    [SerializeField] private GameObject mickPreFab;
    [SerializeField] private Transform EnemySpawnPoint;
    [SerializeField] private Transform EnemySpawnPoint2;

    private int counter = 0; //counter to know how many monsters have been spawned
    [SerializeField] private int countMax;    //control how many monsters will be spawned

    /*
     * function Start() will be called when level 1 initializes
     * Respawn() is called to spawn zombie mickey
     */
    void Start()
    {
        Respawn();
    }
    /*
     * function spawnWave() is referenced to ZombieMickey class to be called
     * every time a mickey is spawned to consisently spawn the monster every 4
     * seconds until the counter == countMax
     */
    public void spawnWave()
    {
        Invoke("Respawn", 2);
        Invoke("Respawn", 4);
    }
    /*
     * Spawns enemy and keeps spawning enemy until counter == max
     * creates a random number form 0-20
     * spawn left side if number <=9 & spawn right side if number >= 10
     */
    public void Respawn() //Respawn enemy
    {
        if (counter != countMax)
        {
            counter += 1;
            int choice = UnityEngine.Random.Range(0, 20);
            if (choice <= 9)
            {
                GameObject enemyClone = (GameObject)Instantiate(mickPreFab,
                   EnemySpawnPoint2.position, EnemySpawnPoint2.rotation);
                enemyClone.GetComponent<SpriteRenderer>().color = new Color(1f, 1f, 1f, 1f);
                enemyClone.SetActive(true);
            }
            else if (choice >= 10)
            {
                GameObject enemyClone = (GameObject)Instantiate(mickPreFab,
                   EnemySpawnPoint.position, EnemySpawnPoint.rotation);
                enemyClone.GetComponent<SpriteRenderer>().color = new Color(1f, 1f, 1f, 1f);
                enemyClone.SetActive(true);
            }
        }
    }

}
