using UnityEngine;

public class Akira : MonoBehaviour
{
    [SerializeField]
    private Animator animator;

    [SerializeField]
    private float walkSpeed = 5f;

    private const string EXCITED_ANIM = "Excited";
    private const string WALK_ANIM = "Walk";
    private const string IDLE_ANIM = "Idle";

    private Vector3 walkStartPosition;
    private Vector3 walkTargetPosition;

    private float walkStartTime;
    private float walkDuration;

    private bool isWalking;

    private void Update ()
    {
	    if (isWalking)
	    {
            float lerp = (Time.time - walkStartTime) / walkDuration;

            Vector3 newPosition = Vector3.Lerp(walkStartPosition, walkTargetPosition, lerp);
            newPosition.y = transform.position.y;

            Quaternion newOrientation = Quaternion.LookRotation(newPosition - transform.position);

            transform.position = newPosition;
            transform.rotation = newOrientation;

            if(lerp >= 1f)
            {
                animator.SetTrigger(EXCITED_ANIM);

                isWalking = false;
            }
	    }
	}

    public void TriggerExcited()
    {
        animator.SetTrigger(EXCITED_ANIM);
    }

    public void WalkToPosition(Vector3 position)
    {
        walkStartPosition = transform.position;
        walkTargetPosition = position;

        walkStartTime = Time.time;
        walkDuration = Vector3.Distance(walkTargetPosition, walkStartPosition) / walkSpeed;

        animator.SetTrigger(WALK_ANIM);

        isWalking = true;
    }
}
