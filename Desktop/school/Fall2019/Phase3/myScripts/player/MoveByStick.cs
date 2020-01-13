using UnityEngine;                  //to use Unity functions
/*
 * To add functionality to
 */
public class MoveByStick : MonoBehaviour
{
    /*
     * Class Objects to access functions within the seperate classes
     */
    [SerializeField] private CharacterController2D controller; //object for 2D controller Class
    [SerializeField] private Animator animator; //object for animation for player
    [SerializeField] private Joystick joystick; //object for the joystick/ joystick class

    public float runSpeed = 60f; //general movement speed for character
    float horizontalMove = 0f; //movement character speed to 0 if neutral
    bool jump = false;
    /* Update is called once per frame
     * puts the joystick input and multiply it to characterSpeed variable
     */
    void Update ()
    {
        if (joystick.Horizontal >= .2f)
        {
            horizontalMove = runSpeed;
        }
        else if (joystick.Horizontal <= -.2f)
        {
            horizontalMove = -runSpeed;
        }
        else
        {
            horizontalMove = 0f;
        }
        animator.SetFloat("Speed", Mathf.Abs(horizontalMove));
        /*if (joystick.Vertical >= .2f)
        {
            jump = true;
        }
        */
    }
    /* Move player character
     * Reads joystick movement & converts it to movemement speed
     */
    void FixedUpdate ()
    {
        if (jump == true)
        {
            //controller.Move(horizontalMove * Time.fixedDeltaTime, false, jump);
            controller.Move(horizontalMove * Time.fixedDeltaTime, jump);
            jump = false;
        }
        else
        {
            controller.Move(horizontalMove * Time.fixedDeltaTime, jump);
        }
    }
}
