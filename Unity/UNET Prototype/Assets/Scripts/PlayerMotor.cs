using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMotor : MonoBehaviour {

    private CharacterController controller;
    private float verticalVelocity;

    private void Start() {
        controller = GetComponent<CharacterController>();
    }

    private void Update() {
        Vector3 inputs = Vector3.zero;
        inputs.x = Input.GetAxis("Horizontal");
        if (controller.isGrounded) {
            verticalVelocity = 0;

            if (Input.GetButton("Jump")) {
                verticalVelocity = 10;
            }
        }
        else {
            verticalVelocity -= 14.0f * Time.deltaTime;
        }

        inputs.y = verticalVelocity;

        controller.Move(inputs * Time.deltaTime);
    }
}
