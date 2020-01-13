using UnityEngine;

public class gameObjective : MonoBehaviour
{
    // Start is called before the first frame update
    [SerializeField] private GameObject Objective;
    private float timer = 0f;

    // Update is called once per frame
    void Update()
    {
        timer += Time.deltaTime;
        if (timer >= 8f)
        {
            Objective.SetActive(false);
            Destroy(gameObject);
        }
    }
}
