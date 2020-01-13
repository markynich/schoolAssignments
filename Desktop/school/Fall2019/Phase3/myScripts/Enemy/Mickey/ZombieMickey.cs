using UnityEngine;
/*
 * Class for Zombie Mickey. Contains health,
 */
public class ZombieMickey : MonoBehaviour
{
    /*
     * class Objects to call functions from the respective classes
     */
    [SerializeField] private Animator animator;   //Animations for player
    [SerializeField] private int health; //health amount variable
    private int damage = 20; //damage variable to send to player class

    //decrease mickey's health, when health reaches 0, call Die() & killCount()
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
        animator.SetBool("Death", true);
    }
    //called during death animation. Hides object then deletes it
    void hideEnemy()
    {
        Destroy(gameObject);
    }
}
