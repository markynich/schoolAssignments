using UnityEngine;
/*
 *  Script to tell the character to shoot an arrow
 *  when it switches states to "isShooting"
 */
public class shootGastonBehavior : StateMachineBehaviour
{
    /*
     *  timer is private float to give the character a 1sec delay to shoot
     *  shoot is a private boolean so that the character only shoots once.
     *  the function that calls Shoot() function is called every frame within
     *  this state
     */
    private float timer;
    private bool shoot;

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * It sets the timer to 1sec and shoot to true
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        timer = 1f;
        shoot = true;
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * It decrements the timer until it hits 0 and shoots an arrow towards the player.
     * After that, it will switch back to state "isIdle"
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if (timer <= 0f)
        {
            if (shoot == true)
            {
                FindObjectOfType<Gaston>().Shoot();
                shoot = false;
            }
            animator.SetTrigger("isIdle");
        }
        timer -= Time.deltaTime;
    }
}
