var speed = 7.0;
var runSpeed = 11.0;
var jumpSpeed = 8.0;
var gravity = 20.0;
var controller : CharacterController;

private var moveDirection = Vector3.zero;
private var grounded : boolean = false;
private var gun : GameObject;

function Start () 
	{
	gun = GameObject.Find("/Player/PlayerObjects/scar-h");
	controller = GetComponent(CharacterController);
	}

function FixedUpdate() {


	if (grounded) {
	
		moveDirection = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
		moveDirection = transform.TransformDirection(moveDirection);
		moveDirection *= speed;
		
		
		if (Input.GetKey (KeyCode.Space )) {
			moveDirection.y = jumpSpeed;
			controller.height = 3.0;
			speed = 7.0;
		}
				
		if (Input.GetKey (KeyCode.C )) {
			controller.height = 1.0;
			speed = 3.0;
		}
		
		if (Input.GetKey (KeyCode.LeftShift ) && controller.height == 3.0) {
		speed = 7.0;
		moveDirection = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
		moveDirection = transform.TransformDirection(moveDirection);
		moveDirection *= runSpeed;
		}
		


	}
	
	moveDirection.y -= gravity * Time.deltaTime;
	var controller : CharacterController = GetComponent(CharacterController);
	var flags = controller.Move(moveDirection * Time.deltaTime);
	
	grounded = (flags & CollisionFlags.CollidedBelow) != 0;
}

@script RequireComponent(CharacterController)