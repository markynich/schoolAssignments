using UnityEngine;
/*
 *  Script to tell the character to following the player
 *  when it switches states to "isFollowing"
 */
public class walkGastonBehavior : StateMachineBehaviour
{
    /*
     *  Positions for Gaston to use and spawn
     */
    private Transform playerPos;    //constantly save the position where the player is
    private Transform leftPlatform; //save position of left platform
    private Transform rightPlatform;//save position of right platform
    private Transform moveLocation; //save position of randomly selected position
    /*
     *  Variables for Gaston to delay attacks, rotate character, etc
     */
    [SerializeField] private float walkSpeed = 4f;  //how fast Gaston can walk
    [SerializeField] private float minTime;         //least amount of time to wait
    [SerializeField] private float maxTime;         //max amount of time to wait
    private int side;                               //Which side to spawn and shoot
    private float timer;                            //timer to allow Gaston to switch to "isShooting"
    private bool flip = true;                       //Flip character object

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Sets multiple variables when the function is called.
     * side contains a random number from 0-10
     * playerPos contains position of player
     * timer contains a random number from minTime to maxTime
     * leftPlatform contains position of leftPlatform
     * rightPlatform contains position of rightPlatform
     * moveLocation contains randomly selected position of left/right platform
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        side = Random.Range(0, 10);
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
        timer = Random.Range(minTime, maxTime);
        leftPlatform = GameObject.FindGameObjectWithTag("leftPlatform").transform;
        rightPlatform = GameObject.FindGameObjectWithTag("rightPlatform").transform;
        if (side <= 4)
        {
            moveLocation = leftPlatform;
        }
        else if (side > 4)
        {
            moveLocation = rightPlatform;
        }
    }

    /*
     * OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Function is called after every frame
     * When timer is set to 0, it will rotate the character, spawn character to moveLocation and
     * switches states to "isShooting"
     * When character is close enough to the player and the checkAtkCD() is true, it will switch
     * states to "isAttacking"
     * Or else, character will continue to follow player
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        timer -= Time.deltaTime;
        //Switch state to "isShooting"
        if (timer <= 0f)
        {
            animator.transform.position = moveLocation.position;
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
            animator.SetTrigger("isShooting");
        }
        //Switch state to "isAttacking"
        else if (Vector2.Distance(animator.transform.position, playerPos.position) < 4f && FindObjectOfType<Gaston>().checkAtkCD() == false)
        {
            animator.SetTrigger("isAttacking");
        }
        //continue following the player
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
