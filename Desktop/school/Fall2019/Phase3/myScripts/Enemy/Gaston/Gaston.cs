using UnityEngine;    //To be able to use generic Unity functions
using UnityEngine.UI; //To be able to use user interface objects
/*
 *  Script which is specifically for Gaston. It contains important functions
 *  and variables for Gaston
 */
public class Gaston : MonoBehaviour
{
    /*
     * class Objects to call functions from the respective classes
     */
    [SerializeField] private Animator animator; //Animations for player
    [SerializeField] private int health;        //health amount variable
    [SerializeField] private Slider HealthBar;  //healthbar connected to health
    private float timer = 0f;                   //timer to delay attacks
    [SerializeField] private float cooldown;    //variable for how long between atks
    [SerializeField] private Transform firePoint;   //position of where arrows are shot
    [SerializeField] private GameObject arrowPreFab;//shoot out arrow objects when called
    /*
     * Called when Gaston Object is created
     * Setting Gaston state to "isFollowing"
     */
    private void Start()
    {
        animator.SetTrigger("isFollowing");
    }
    /*
     * Called every frame
     * Updates the timer variable and health bar
     */
    private void Update()
    {
        timer += Time.deltaTime;
        HealthBar.value = health;
    }
    /*
     * To decrease health variable whenever Gaston is hit by a lazer
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
    //Other functions outside of the class can see if Gaston is ready to atk
    public bool checkAtkCD()
    {
        return timer <= cooldown;
    }
    //resets timer back to 0sec
    public void resetAtkCD()
    {
        timer = 0f;
    }
    // Death animation is activated.
    void Die()
    {
        animator.SetBool("Death", true);
    }
    //Creates the arrow everytime this function is called.
    public void Shoot()
    {
        Instantiate(arrowPreFab, firePoint.position, firePoint.rotation);
    }
    //Used for "Death" state to destroy object
    void hideEnemy()
    {
        Destroy(gameObject);
    }
}
