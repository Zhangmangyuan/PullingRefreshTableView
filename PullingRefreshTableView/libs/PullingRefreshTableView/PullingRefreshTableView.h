//
//  PullingRefreshTableView.h
//  PullingTableView
//
//  Created by danal on 3/6/12.If you want use it,please leave my name here
//  Copyright (c) 2012 danal Luo. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    kPRStateNormal = 0,                     //正常状态
    kPRStatePulling = 1,                    //拉动中
    kPRStateLoading = 2,                    //加载中
    kPRStateHitTheEnd = 3                   //遇到底部
} PRState;

@interface LoadingView : UIView {
    UILabel *_stateLabel;
    UILabel *_dateLabel;
    UIImageView *_arrowView;
    UIActivityIndicatorView *_activityView;
    CALayer *_arrow;
    BOOL _loading;
}
@property (nonatomic,getter = isLoading) BOOL loading;    
@property (nonatomic,getter = isAtTop) BOOL atTop;
@property (nonatomic) PRState state;

- (id)initWithFrame:(CGRect)frame atTop:(BOOL)top;

- (void)updateRefreshDate:(NSDate *)date;
- (void)setState:(PRState)state animated:(BOOL)animated;
@end

@protocol PullingRefreshTableViewDelegate;

@interface PullingRefreshTableView : UITableView <UIScrollViewDelegate>{
    LoadingView *_headerView;           //表格头部视图
    LoadingView *_footerView;           //表格根部视图
    UILabel *_msgLabel;                 //消息标签
    BOOL _loading;                      //是否在加载中
    BOOL _isFooterInAction;             //是否加载更多中
    NSInteger _bottomRow;               //底部的行数
}
@property (assign,nonatomic) id <PullingRefreshTableViewDelegate> pullingDelegate;
@property (nonatomic) BOOL autoScrollToNextPage;
@property (nonatomic) BOOL reachedTheEnd;
@property (nonatomic,getter = isHeaderOnly) BOOL headerOnly;

//added  by liangliang
@property (nonatomic,getter = isFooterOnly) BOOL footerOnly;

- (id)initWithFrame:(CGRect)frame pullingDelegate:(id<PullingRefreshTableViewDelegate>)aPullingDelegate;

- (void)tableViewDidScroll:(UIScrollView *)scrollView;

- (void)tableViewDidEndDragging:(UIScrollView *)scrollView;

- (void)tableViewDidFinishedLoading;

- (void)tableViewDidFinishedLoadingWithMessage:(NSString *)msg;

- (void)launchRefreshing;

- (void)flashMessage:(NSString *)msg;
@end



@protocol PullingRefreshTableViewDelegate <NSObject>

@required
- (void)pullingTableViewDidStartRefreshing:(PullingRefreshTableView *)tableView;

@optional
//Implement this method if headerOnly is false
- (void)pullingTableViewDidStartLoading:(PullingRefreshTableView *)tableView;
//Implement the follows to set date you want,Or Ignore them to use current date 
- (NSDate *)pullingTableViewRefreshingFinishedDate;
- (NSDate *)pullingTableViewLoadingFinishedDate;
@end

//Usage example
/*
_tableView = [[PullingRefreshTableView alloc] initWithFrame:frame pullingDelegate:aPullingDelegate];
[self.view addSubview:_tableView];
_tableView.autoScrollToNextPage = NO;
_tableView.delegate = self;
_tableView.dataSource = self;
*/