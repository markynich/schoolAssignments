using UnityEngine;
/*
 *  Script which holds important variables and functions
 *  for zombie goofy. It is the base class for goofy objects
 */
public class ZombieGoofy : MonoBehaviour
{
    /*
     * class Objects to call functions from the respective classes
     */
    [SerializeField] private Animator animator;   //Animations for player
    [SerializeField] private int health; //health amount variable
    /*
     * To decrease health variable whenever Goofy is hit by lazer
     * If health is 0, call Die() function and killCount() function
     */
    public void TakeDamage(int damage)
    {
        health -= damage;
        if (health == 0)
        {
            Die();
            FindObjectOfType<PlayerChar>().killCount();
        }
    }
    // Death animation is activated.
    void Die()
    {
        animator.SetTrigger("Death");
    }
    //called during death animation. Hides object then deletes it
    void hideEnemy()
    {
        Destroy(gameObject);
    }
}
