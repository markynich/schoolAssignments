using UnityEngine;
/*
 * Add attack functionality to Zombie Mickey  
 */
public class mickeyAtk : MonoBehaviour
{
    private int damage = 5; //damage variable to send to player class

    //If Zombie Mickey attack collides with player, then send damage to player
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag.Equals("Player"))
        {
            PlayerChar playerHit = col.GetComponent<PlayerChar>();
            if (playerHit != null)
            {
               playerHit.TakeDamage(damage);
            }
        }
    }
}
