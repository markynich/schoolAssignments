using UnityEngine;
/*
 *  Script to run when Gaston switches to state "isAttacking"
 *  Whenever the leg hits the player, it will send damage to player class
 */
public class GastonKick : MonoBehaviour
{
    private int damage = 20; //damage variable to send to player class

    //If Gaston's left leg collides with player, it will damage the player
    void OnTriggerEnter2D(Collider2D col)
    {
            PlayerChar playerHit = col.GetComponent<PlayerChar>();
            if (playerHit != null)
            {
                playerHit.TakeDamage(damage);
            }
    }
}
