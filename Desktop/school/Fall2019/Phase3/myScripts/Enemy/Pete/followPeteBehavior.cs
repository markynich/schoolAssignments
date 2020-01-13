using UnityEngine;
/*
 *  Script to tell the character to following the player
 *  when it switches states to "isFollowing"
 */
public class followPeteBehavior : StateMachineBehaviour
{
    private Transform playerPos; //constantly save the position where the player is
    private bool flip = true;                       //Flip character object
    [SerializeField] private float walkSpeed = 3f;  //how fast Pete can walk
    private float timer;                            //timer to allow Gaston to switch to "isShooting"
    [SerializeField] private float minTime;         //least amount of time to wait
    [SerializeField] private float maxTime;         //max amount of time to wait

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Sets multiple variables when the function is called.
     * playerPos contains position of player
     * timer contains a random number from minTime to maxTime
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
        timer = Random.Range(minTime, maxTime);
    }
    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Function is called after every frame
     * When timer is set to 0, it will switch states to "isRushing"
     * When character is close enough to the player and the checkAtkCD() is true, it will switch
     * states to "isAttacking"
     * Or else, character will continue to follow player
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        timer -= Time.deltaTime;
        if (timer <= 0f)
        {
            animator.SetTrigger("isRushing");
        }
        else if (Vector2.Distance(animator.transform.position, playerPos.position) < 4f && FindObjectOfType<bossPete>().checkAtkCD() == false)
        {
            animator.SetTrigger("isAttacking");
        }
        else
        {
            animator.transform.position = Vector2.MoveTowards(animator.transform.position, playerPos.position, walkSpeed * Time.deltaTime);
            if (playerPos.position.x < animator.transform.position.x && flip == false)
            {
                animator.transform.Rotate(0f, 180f, 0f);
                flip = true;
            }
            else if (playerPos.position.x > animator.transform.position.x && flip == true)
            {
                animator.transform.Rotate(0f, 180f, 0f);
                flip = false;
            }
        }
    }
}
