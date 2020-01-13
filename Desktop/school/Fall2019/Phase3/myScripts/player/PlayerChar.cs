using UnityEngine;
using UnityEngine.UI;
/*
 * Player health system. Controls health & death animation
 */
public class PlayerChar : MonoBehaviour
{
    [SerializeField] private Animator animator; //object to use functions from class
    [SerializeField] private Slider HealthBar;
    private int counter = 0; //if counts how many enemies the player has beaten
    [SerializeField] private int killMax;
    public int health = 100; //health amount for player

    /*
     * updates every frame
     * connects value of class health variable to healthBar value
     */
    private void Update()
    {
        HealthBar.value = health;
    }
    /*
     * if player defeats "num" amount of enemies, game is over and player wins
     * win animation is turn on
     */
    public void killCount()
    {
        counter += 1;
        if (counter == killMax)
        {
            FindObjectOfType<gameManager>().gameWon();
        }
    }
    /*
     * Everytime a player is hit, it will be recorded and decreases the health.
     * If player health hits 0, Die() function is called
     */
    public void TakeDamage(int damage)
    {
        health -= damage;
        if (health <= 0)
        {
            Die();
        }
    }
    /*
     * Death animation is actived, user will not be able to move, and losing
     * animation is turned on
     */
    void Die()
    {
        animator.SetBool("Death", true);
        FindObjectOfType<CharacterController2D>().enabled = false;
        FindObjectOfType<gameManager>().gameOver();
    }
}
