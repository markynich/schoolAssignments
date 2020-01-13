using UnityEngine;
/*
 *  Script to spawn enemies when user hits a certain
 *  object that is attached to this script
 */
public class triggerSpawn : MonoBehaviour
{
    [SerializeField] private int spawnStart;
    [SerializeField] private int spawnEnd;
    [SerializeField] private EnemySpawn enemyspawnFile;
    private bool contactHit = false;

    void OnTriggerEnter2D(Collider2D hitInfo)
    {
            if (hitInfo.gameObject.tag == "Player")
            {
                for (int i = spawnStart; i <= spawnEnd; i++)
                {
                    enemyspawnFile.Spawn(i);
                }
            }
        Destroy(gameObject);
    }
}
