using UnityEngine;
/*
 *  Script to tell the character to attack
 *  when it switches states to "isAttacking"
 */
public class kickGastonBehavior : StateMachineBehaviour
{
    /*
     *  timer is a private float variable to keep the attacking duration to 1sec
     */
    private float timer;
    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Sets timer to 1 sec
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        timer = 1f;
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Function is called every frame, within the duration of the state, character is attacking
     * When timer hits 0, character will stop attacking and switch to state "isIdle"
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (timer <= 0)
        {
            animator.SetTrigger("isIdle");
        }
        else
        {
            timer -= Time.deltaTime;
        }
    }
}
