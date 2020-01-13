using UnityEngine;    //To be able to use generic Unity functions
using UnityEngine.UI; //To be able to use user interface objects
/*
 *  Script which is specifically for Gaston. It contains important functions
 *  and variables for Gaston
 */
public class bossPete : MonoBehaviour
{
    /*
     * class Objects to call functions from the respective classes
     */
    [SerializeField] private Animator animator; //Animations for player
    [SerializeField] private int health;        //health amount variable
    [SerializeField] private Slider HealthBar;  //healthbar connected to health
    private float timer = 0f;                   //timer to delay attacks
    [SerializeField] private float cooldown;    //variable for how long between atks
    /*
     * Called when bossPete Object is created
     * Setting bossPete state to "isFollowing"
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
     * To decrease health variable whenever Pete is hit by lazer
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
    //When Pete hits either leftWall or rightWall, switch state to "isIdle"
    void OnTriggerEnter2D(Collider2D hitInfo)
    {
        if (hitInfo.gameObject.tag == "leftWall" || hitInfo.gameObject.tag == "rightWall")
        {
            animator.SetTrigger("isIdle");
        }
    }
    //called during death animation. Hides object then deletes it
    void hideEnemy()
    {
        Destroy(gameObject);
    }
}
