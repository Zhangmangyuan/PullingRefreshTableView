//
//  MainViewController.h
//  PullingRefreshTableView
//
//  Created by 张茫原 on 13-4-5.
//  Copyright (c) 2013年 张茫原. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PullingRefreshTableView.h"

@interface MainViewController : UIViewController<PullingRefreshTableViewDelegate,UITableViewDataSource,UITableViewDelegate>
{

}

@property (nonatomic, assign) BOOL refreshing;
@property (nonatomic, retain) PullingRefreshTableView * tableView;

@end







