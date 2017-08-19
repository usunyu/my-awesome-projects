/**
 * Copyright (c) 2017 Razeware LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Notwithstanding the foregoing, you may not use, copy, modify, merge, publish,
 * distribute, sublicense, create a derivative work, and/or sell copies of the
 * Software in any work that is designed, intended, or marketed for pedagogical or
 * instructional purposes related to programming, coding, application development,
 * or information technology.  Permission for such use, copying, modification,
 * merger, publication, distribution, sublicensing, creation of derivative works,
 * or sale is expressly withheld.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *  Created by Richard Turton on 19/04/2016.
 */

import UIKit

struct Emoji {
  let name: String
  let character: String
}

class FaceSource: NSObject {
  lazy var replacements: [Emoji] = {
    let faces = "😀,😂,💩,🦄,😎,😷,😱,🤔,😍"
    let names = "smile,cry,poo,unicorn,sunglasses,mask,scream,think,love"
    return zip(faces.components(separatedBy: ","), names.components(separatedBy: ","))
      .map({ let (face, name) = $0;
        return Emoji(name: name, character: face)
      })
  }()
  
  var collectionView: UICollectionView?
  var faceChosen: ((_ face: UIImage) -> ())?
}

extension FaceSource {
  func selectFace(_ string: String) {
    if let index = replacements.index(where: { string.lowercased().contains($0.name) }),
      let collectionView = collectionView {
      let indexPath = IndexPath(item: index, section: 0)
      collectionView.selectItem(at: indexPath, animated: true, scrollPosition: .centeredVertically)
      self.collectionView(collectionView, didSelectItemAt: indexPath)
    }
  }
}



extension FaceSource: UICollectionViewDataSource {
  func numberOfSections(in collectionView: UICollectionView) -> Int {
    return 1
  }
  func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
    return replacements.count
  }
  func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
    let faceCell = collectionView.dequeueReusableCell(withReuseIdentifier: "FaceCell", for: indexPath) as! FaceCell
    faceCell.label.text = replacements[indexPath.item].character
    return faceCell
  }
}

extension FaceSource: UICollectionViewDelegate {
  func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
    
    let emoji = replacements[indexPath.item].character
    let attributes = [NSAttributedStringKey.font: UIFont.systemFont(ofSize: 100)]
    
    let adjustment: CGFloat = 10.0
    let boundingSize = emoji.size(withAttributes: attributes)
    var adjustedSize = boundingSize
    adjustedSize.width -= adjustment
    adjustedSize.height -= adjustment
    let drawingRect = CGRect(x: adjustment * -0.5, y: adjustment * -0.5, width: boundingSize.width, height: boundingSize.height)
    
    UIGraphicsBeginImageContextWithOptions(adjustedSize, false, 0)
    emoji.draw(in: drawingRect, withAttributes: attributes)
    let face = UIGraphicsGetImageFromCurrentImageContext()
    UIGraphicsEndImageContext()
    faceChosen?(face!)
  }
}
