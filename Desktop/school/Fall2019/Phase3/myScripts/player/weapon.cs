using UnityEngine;
/*
 * Generates the lazer bullets whenever the player hits the shoot button
 */
public class weapon : MonoBehaviour
{
    /*
     * firePoint references to position of player's weapon
     * lazerPreFab references to the gameObject of the lazer
     */
    [SerializeField] private Transform firePoint;
    [SerializeField] private GameObject lazerPreFab;

    //Creates the lazer everytime this function is called.
    public void Shoot()
    {
        Instantiate(lazerPreFab, firePoint.position, firePoint.rotation);
    }
}
