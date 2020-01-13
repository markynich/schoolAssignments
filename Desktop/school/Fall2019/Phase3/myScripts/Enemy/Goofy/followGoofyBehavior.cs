using UnityEngine;
/*
 *  Script to tell the character to follow the player
 *  when it switches states to "isFollowing"
 */
public class followGoofyBehavior : StateMachineBehaviour
{
    /*
     *  playerPos to save position of the player
     *  flip is one of the variables to control when the character should flip
     *  walkSpeed is a Serialiazed field to control the value within Unity Program
     */
    private Transform playerPos;
    private bool flip = true;
    [SerializeField] private float walkSpeed;

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Save the current player position within playerPos
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Function is called after every frame
     * When character is close enough to the player, it will switch states to "isAttacking"
     * Or else, character will continue to follow player
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (Vector2.Distance(animator.transform.position, playerPos.position) < 3f)
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
