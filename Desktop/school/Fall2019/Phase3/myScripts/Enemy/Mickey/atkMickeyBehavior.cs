using UnityEngine;
/*
 *  Script to tell the character to atk within a certain duration
 *  when it switches states to "isAttacking"
 */
public class atkMickeyBehavior : StateMachineBehaviour
{
    private float timer; //timer is a variable for duration of atk
    /* OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Sets timer to 1 sec
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        timer = 1f;
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * When timer is set to 0, it will switch states to "isIdle"
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
