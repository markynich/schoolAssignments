using UnityEngine;
/*
 *  Script to tell the character to stay idle and not move
 *  when it switches states to "isIdle"
 */
public class idlePeteBehavior : StateMachineBehaviour
{
    private Transform playerPos; //constantly save the position where the player is

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Grabs the current player's position and stores it in playerPos
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * When the player is far enough from Gaston, it will switch states to "isFollowing"
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (Vector2.Distance(animator.transform.position, playerPos.position) > 3f)
        {
            animator.SetTrigger("isFollowing");
        }
    }
}
