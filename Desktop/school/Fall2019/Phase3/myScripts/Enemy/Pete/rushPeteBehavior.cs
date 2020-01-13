using UnityEngine;

public class rushPeteBehavior : StateMachineBehaviour
{
    private Transform playerPos;    //constantly save the position where the player is
    private Transform leftWall;     //save position of the "leftWall"
    private Transform rightWall;    //save position of the "rightWall"
    private Transform moveLocation; //save randomly picked location
    [SerializeField] private float rushSpeed; //speed of rushing movement

    /*
     * OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
     * Sets multiple variables when the function is called.
     * playerPos contains position of player
     * leftWall contains position of leftWall
     * rightWall contains position of rightWall
     * moveLocation contains randomly selected position of left/right wall
     */
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        playerPos = GameObject.FindGameObjectWithTag("Player").transform;
        leftWall = GameObject.FindGameObjectWithTag("leftWall").transform;
        rightWall = GameObject.FindGameObjectWithTag("rightWall").transform;
        if (playerPos.position.x < animator.transform.position.x)
        {
            moveLocation = leftWall;
        }
        else if (playerPos.position.x > animator.transform.position.x)
        {
            moveLocation = rightWall;
        }
    }

    /* OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
     * Function called every frame
     * Move character towards the position that was randomly chosen and stored within moveLocation
     */
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        animator.transform.position = Vector2.MoveTowards(animator.transform.position, moveLocation.position, rushSpeed * Time.deltaTime);
    }
}
