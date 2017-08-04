//
//  ViewController.swift
//  Hello-AR
//
//  Created by Yu Sun on 8/2/17.
//  Copyright © 2017 usunyu. All rights reserved.
//

import UIKit
import SceneKit
import ARKit

class ViewController: UIViewController, ARSCNViewDelegate {
    
    var sceneView: ARSCNView!
    
    private let label: UILabel = UILabel()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.sceneView = ARSCNView(frame: self.view.frame)
        
        self.sceneView.debugOptions = [ARSCNDebugOptions.showFeaturePoints]
        
        self.view.addSubview(self.sceneView)
        
        // Set the view's delegate
        sceneView.delegate = self
        
        // Show statistics such as fps and timing information
        sceneView.showsStatistics = true
        
        // Create a new scene
        let scene = SCNScene()
        
        //        let textGeometry = SCNText(string: "Hello World", extrusionDepth: 1.0)
        //        textGeometry.firstMaterial?.diffuse.contents = UIColor.black
        //
        //        let textNode = SCNNode(geometry: textGeometry)
        //        textNode.position = SCNVector3(0, 0.1, -0.5)
        //        textNode.scale = SCNVector3(0.01, 0.01, 0.01)
        //
        //        scene.rootNode.addChildNode(textNode)
        
//        let box = SCNBox(width: 0.2, height: 0.2, length: 0.2, chamferRadius: 0)
//
//        let material = SCNMaterial()
//        material.name = "Color"
//        material.diffuse.contents = UIImage(named : "brick.jpg")
//
//        let node = SCNNode()
//        node.geometry = box
//        node.geometry?.materials = [material]
//        node.position = SCNVector3(0, 0.1, -0.5)
//
//        scene.rootNode.addChildNode(node)
//
//        let tapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapped))
//        self.sceneView.addGestureRecognizer(tapGestureRecognizer)
        
//        let sphere = SCNSphere(radius: 0.2)
//
//        let sphereMaterial = SCNMaterial()
//        sphereMaterial.diffuse.contents = UIImage(named : "earthmap.jpg")
//
//        let sphereNode = SCNNode()
//        sphereNode.geometry = sphere
//        sphereNode.geometry?.materials = [sphereMaterial]
//        sphereNode.position = SCNVector3(0.5, 0.1, -1)
//
//        scene.rootNode.addChildNode(sphereNode)
        
        // Set the scene to the view
        sceneView.scene = scene
    }
    
    @objc func tapped(recongizer: UITapGestureRecognizer) {
        
        let sceneView = recongizer.view as! SCNView
        let touchLocation = recongizer.location(in: sceneView)
        let hitResult = sceneView.hitTest(touchLocation, options: [:])
        
        if (!hitResult.isEmpty) {
            let node = hitResult[0].node
            let material = node.geometry?.material(named: "Color")
            
            material?.diffuse.contents = UIColor.random()
        }
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
        
        DispatchQueue.main.async {
            self.label.text = "Plane Detected"
            
            UIView.animate(withDuration: 3.0, animations: {
                self.label.alpha = 1.0
            }) { (completion: Bool) in
                self.label.alpha = 0.0
            }
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Pause the view's session
        sceneView.session.pause()
    }
}
