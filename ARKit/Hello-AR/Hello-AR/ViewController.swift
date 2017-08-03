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
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.sceneView = ARSCNView(frame: self.view.frame)
        self.view.addSubview(self.sceneView)
        
        // Set the view's delegate
        sceneView.delegate = self
        
        // Show statistics such as fps and timing information
        sceneView.showsStatistics = true
        
        // Create a new scene
        let scene = SCNScene()
        
        let textGeometry = SCNText(string: "Hello World", extrusionDepth: 1.0)
        textGeometry.firstMaterial?.diffuse.contents = UIColor.black
        
        let textNode = SCNNode(geometry: textGeometry)
        textNode.position = SCNVector3(0, 0.1, -0.5)
        textNode.scale = SCNVector3(0.01, 0.01, 0.01)
        
        scene.rootNode.addChildNode(textNode)
        
//        let box = SCNBox(width: 0.2, height: 0.2, length: 0.2, chamferRadius: 0)
//
//        let material = SCNMaterial()
//        material.diffuse.contents = UIColor.red
//
//        let node = SCNNode()
//        node.geometry = box
//        node.geometry?.materials = [material]
//        node.position = SCNVector3(0, 0.1, -0.5)
//
//        scene.rootNode.addChildNode(node)
        
        // Set the scene to the view
        sceneView.scene = scene
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        // Create a session configuration
        let configuration = ARWorldTrackingSessionConfiguration()
        
        // Run the view's session
        sceneView.session.run(configuration)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        // Pause the view's session
        sceneView.session.pause()
    }
}
