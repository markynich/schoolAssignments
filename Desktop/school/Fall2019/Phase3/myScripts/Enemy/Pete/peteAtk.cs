using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class peteAtk : MonoBehaviour
{
    private int damage = 30; //damage variable to send to player class
    //If Pete is within range, attack player and send damage to player
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag.Equals("Player"))
        {
            PlayerChar playerHit = col.GetComponent<PlayerChar>();
            if (playerHit != null && FindObjectOfType<bossPete>().checkAtkCD() == true)
            {
                playerHit.TakeDamage(damage);
            }
            FindObjectOfType<bossPete>().resetAtkCD();
        }
    }
}
