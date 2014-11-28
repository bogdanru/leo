<?php
/**
 * @file
 * Demo drush command for creating a node and assign it front page.
 */

/**
 * Implements hook_drush_command().
 */
function demo_fp_drush_command() {

  $items['demo-fp'] = array(
    'description' => 'Creating a node and assign it front page.',
    'aliases' => array('dfp'),
    'options' => array(
      'title' => 'Node title.',
    ),
  );

  return $items;
}

/**
 * Callback for the demo-fp command
 */
function drush_demo_fp() {
  global $language;
  $node = new stdClass();
  $node->type = 'page';
  $node->status = 1;
  node_object_prepare($node);
  $node->uid = 1;
  
  $title = drush_get_option('title', 'My front page');
  $node->title = $title;
  $node->language = $language->language;
  if($node = node_submit($node)) {
    node_save($node);
  }
  variable_set('site_frontpage', 'node/' . $node->nid);
}