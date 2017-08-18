//
//  LightViewController.swift
//  Hello-AR
//
//  Created by Yu Sun on 8/18/17.
//  Copyright © 2017 usunyu. All rights reserved.
//

import UIKit
import SceneKit
import ARKit

class LightViewController: UIViewController, ARSCNViewDelegate {
    
    var sceneView: ARSCNView!
    var planes = [OverlayPlane]()
    
    var boxes = [SCNNode]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.sceneView = ARSCNView(frame: self.view.frame)
        
        self.sceneView.debugOptions = [ARSCNDebugOptions.showFeaturePoints,ARSCNDebugOptions.showWorldOrigin]
        
        self.view.addSubview(self.sceneView)
        
        //self.sceneView.autoenablesDefaultLighting = true
        
        // Set the view's delegate
        sceneView.delegate = self
        
        // Show statistics such as fps and timing information
        sceneView.showsStatistics = true
        
        let scene = SCNScene()
        
        // Set the scene to the view
        sceneView.scene = scene
        
        registerGestureRecognizers()
        setupPlaneToggleSwitch()
        insertSpotLight(position: SCNVector3(0,1.0,0))
    }
    
    private func insertSpotLight(position :SCNVector3) {
        
        let spotLight = SCNLight()
        spotLight.type = .spot
        spotLight.spotInnerAngle = 45
        spotLight.spotOuterAngle = 45
        
        let spotNode = SCNNode()
        spotNode.name = "SpotNode"
        spotNode.light = spotLight
        spotNode.position = position
        
        spotNode.eulerAngles = SCNVector3(-Double.pi/2.0,0,-0.2)
        self.sceneView.scene.rootNode.addChildNode(spotNode)
    }
    
    private func setupPlaneToggleSwitch() {
        
        let planeToggleSwitch = UISwitch(frame: CGRect(x: 10, y: self.sceneView.frame.height - 44, width: 100, height: 33))
        planeToggleSwitch.addTarget(self, action: #selector(planeSwitchToggled), for: .valueChanged)
        self.sceneView.addSubview(planeToggleSwitch)
    }
    
    // turn off the plane detection and remove the grid from the plane
    @objc func planeSwitchToggled(planeSwitch :UISwitch) {
        
        let configuration = self.sceneView.session.configuration as! ARWorldTrackingSessionConfiguration
        
        configuration.planeDetection = []
        self.sceneView.session.run(configuration, options: [])
        
        // turn off the grid
        for plane in self.planes {
            plane.planeGeometry.materials.forEach { material in
                material.diffuse.contents = UIColor.clear
            }
        }
    }
    
    private func registerGestureRecognizers() {
        
        let tapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapped))
        
        self.sceneView.addGestureRecognizer(tapGestureRecognizer)
    }
    
    func renderer(_ renderer: SCNSceneRenderer, updateAtTime time: TimeInterval) {
        
        
        let estimate = self.sceneView.session.currentFrame?.lightEstimate
        
        if estimate == nil {
            return
        }
        
        let spotNode = self.sceneView.scene.rootNode.childNode(withName: "SpotNode", recursively: true)
        spotNode?.light?.intensity = (estimate?.ambientIntensity)!
    }
    
    
    @objc func tapped(recognizer :UIGestureRecognizer) {
        
        let sceneView = recognizer.view as! ARSCNView
        let touchLocation = recognizer.location(in: sceneView)
        
        let hitTestResult = sceneView.hitTest(touchLocation, types: .existingPlaneUsingExtent)
        
        if !hitTestResult.isEmpty {
            
            guard let hitResult = hitTestResult.first else {
                return
            }
            addBox(hitResult :hitResult)
        }
    }
    
    private func addBox(hitResult :ARHitTestResult) {
        
        let boxGeometry = SCNBox(width: 0.2, height: 0.2, length: 0.1, chamferRadius: 0)
        let material = SCNMaterial()
       // material.diffuse.contents = UIColor.red
        
        boxGeometry.materials = [material]
        
        let boxNode = SCNNode(geometry: boxGeometry)
        boxNode.physicsBody = SCNPhysicsBody(type: .dynamic, shape: nil)
        boxNode.physicsBody?.categoryBitMask = BodyType.box.rawValue
        
        self.boxes.append(boxNode)
        
        boxNode.position = SCNVector3(hitResult.worldTransform.columns.3.x,hitResult.worldTransform.columns.3.y + Float(0.5), hitResult.worldTransform.columns.3.z)
        
        self.sceneView.scene.rootNode.addChildNode(boxNode)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        // Create a session configuration
        let configuration = ARWorldTrackingSessionConfiguration()
        
        configuration.planeDetection = .horizontal
        
        // Run the view's session
        sceneView.session.run(configuration)
    }
    
    func renderer(_ renderer: SCNSceneRenderer, didAdd node: SCNNode, for anchor: ARAnchor) {
        
        if !(anchor is ARPlaneAnchor) {
            return
        }
        
        let plane = OverlayPlane(anchor: anchor as! ARPlaneAnchor)
        self.planes.append(plane)
        node.addChildNode(plane)
    }
    
    func renderer(_ renderer: SCNSceneRenderer, didUpdate node: SCNNode, for anchor: ARAnchor) {
        
        let plane = self.planes.filter { plane in
            return plane.anchor.identifier == anchor.identifier
            }.first
        
        if plane == nil {
            return
        }
        
        plane?.update(anchor: anchor as! ARPlaneAnchor)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Pause the view's session
        sceneView.session.pause()
    }
}
