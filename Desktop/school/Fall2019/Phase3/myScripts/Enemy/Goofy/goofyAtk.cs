using UnityEngine;

public class goofyAtk : MonoBehaviour
{
    private int damage = 30; //damage variable to send to player class

    //If Goofy's attack collides with the player, it sends damage to player
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag.Equals("Player"))
        {
            //player object to get info
            PlayerChar playerHit = col.GetComponent<PlayerChar>();
            if (playerHit != null)
            {
                playerHit.TakeDamage(damage); //sends damage to player class
            }
        }
    }
}
