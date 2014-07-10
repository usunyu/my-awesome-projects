//
//  SweetTableViewCell.swift
//  SwifferApp
//
//  Created by Sun on 7/10/14.
//  Copyright (c) 2014 Sun. All rights reserved.
//

import UIKit

class SweetTableViewCell: UITableViewCell {

    @IBOutlet strong var usernameLabel: UILabel = UILabel()
    @IBOutlet strong var timestampLabel: UILabel = UILabel()
    @IBOutlet strong var sweetTextView: UITextView = UITextView()
    
    init(style: UITableViewCellStyle, reuseIdentifier: String) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        // Initialization code
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
