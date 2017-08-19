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
 */

import Foundation

let recordingNames: [(String, String, String, String?)] = [
  ("It's Like That", "Run DMC", "01_ItsLikeThat.m4a", "en_GB"),
  ("Jump Around", "House of Pain", "02_JumpAround.m4a", "en_GB"),
  ("Gangsta's Paradise", "Coolio", "03_GangstasParadise.m4a", "en_GB"),
  ("U Can't Touch This", "MC Hammer", "04_UCantTouchThis.m4a", "en_GB"),
  ("Rapper's Delight", "Sugarhill Gang", "05_RappersDelight.m4a", "en_GB"),
  ("I Like Big Butts", "Sir Mix-a-Lot", "06_ILikeBigButts.m4a", "en_GB"),
  ("One Dance", "Drake", "07_OneDance.m4a", "en_GB"),
  ("No Sleep 'Til Brooklyn", "Beastie Boys", "08_NoSleepTilBrooklyn.m4a", "en_GB"),
  ("Informer", "Snow", "09_Informer.m4a", "en_GB"),
  ("Raise Your Hands", "โจอี้ บอย", "10_RaiseYourHands.m4a", "th_TH")
]

struct Recording {
  let title: String
  let subtitle: String
  let audio: URL
  let locale: Locale?
  
  init(title: String, subtitle: String, filename: String, locale: Locale?) {
    self.title = title
    self.subtitle = subtitle
    self.audio = Bundle.main.url(forResource: filename, withExtension: .none)!
    self.locale = locale
  }
  
  static func defaultRecordings() -> [Recording] {
    return recordingNames.map({ let (title, subtitle, filename, localeName) = $0;
      let locale: Locale?
      if let localeName = localeName {
        locale = Locale(identifier: localeName)
      } else {
        locale = .none
      }
      return Recording(title: title, subtitle: subtitle, filename: filename, locale: locale)
    })
  }
}



