using UnityEngine;
/*
 * Script for lazer bullet animation. When Lazer GameObject is created, it will
 * moves towards the direction it was created. If the bullet collides with the
 * enemy, it will destroy itself and send damage amount to enemy class.
 */
public class Lazer : MonoBehaviour
{
    [SerializeField] private float speed = 40f;
    [SerializeField] private int damage = 20;
    [SerializeField] private Rigidbody2D rb;
    private Transform playerPos;

    // called everytime the lazer is created.
    private void Start()
    {
		rb.velocity = transform.right * speed;
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
    }
    private void Update()
    {
        if (Vector2.Distance(transform.position, playerPos.position) > 16.5f)
        {
            Destroy(gameObject);
        }
    }
    /*
     * If lazer collides with enemy, object destroys and sends damage to enemy class
     */
    void OnTriggerEnter2D (Collider2D hitInfo)
	{
        bossPete pete = hitInfo.GetComponent<bossPete>();
        if (pete != null)
        {
            pete.TakeDamage(damage);
            Destroy(gameObject);
        }
		ZombieMickey mickey = hitInfo.GetComponent<ZombieMickey>();
        if (mickey != null)
		{
			mickey.TakeDamage(damage);
            Destroy(gameObject);
		}
        ZombieGoofy goofy = hitInfo.GetComponent<ZombieGoofy>();
        if (goofy != null)
        {
            goofy.TakeDamage(damage);
            Destroy(gameObject);
        }
        Gaston gaston = hitInfo.GetComponent<Gaston>();
        if (gaston != null)
        {
            gaston.TakeDamage(damage);
            Destroy(gameObject);
        }
        Destroy(gameObject);
	}
}
