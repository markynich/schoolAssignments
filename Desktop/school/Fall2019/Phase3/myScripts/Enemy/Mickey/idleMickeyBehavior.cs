using UnityEngine;
/*
 *  Script to tell the character to stay still
 *  when it switches states to "isIdle"
 */
public class idleMickeyBehavior : StateMachineBehaviour
{
    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Simple function to switch to "isFollowing"
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
            animator.SetTrigger("isFollowing");
    }
}
