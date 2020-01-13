using UnityEngine;
/*
 *  Script to detect collision with objects and accelerate
 *  the arrow to move towards the player
 */
public class Arrow : MonoBehaviour
{
    /*
     *  speed is a private float that is serialized to see the value within the Unity Program
     *  damage is a private int that is serialized to see the value within the Unity Program
     *  rb is a private Rigicbody2D object to use the variables/functions from the class which
     *  is attached to the arrow object
     */
    [SerializeField] private float speed = 40f;
    [SerializeField] private int damage = 20;
    [SerializeField] private Rigidbody2D rb;

    /*
     *  Start() function is just like a constructor.
     *  When the script file is called, it will immediately run Start()
     *  Start() moves to arrow towards the player
     */
    private void Start()
    {
        rb.velocity = transform.right * speed;
    }
    /*
     * If arrow collides with player, it sends damage to player class
     * If arrow collides with lazer, it will immediately destroy the objects
     * Any other collision will destroy the game object
     */
    void OnTriggerEnter2D(Collider2D hitInfo)
    {
        PlayerChar player = hitInfo.GetComponent<PlayerChar>();
        if (player != null)
        {
            player.TakeDamage(damage);
            Destroy(gameObject);
        }
        Lazer lazerHit = hitInfo.GetComponent<Lazer>();
        if (lazerHit != null)
        {
            Destroy(gameObject);
        }
        Destroy(gameObject);
    }
}
