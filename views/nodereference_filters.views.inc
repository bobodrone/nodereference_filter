<?php
// $Id$

/*
 * @file
 * Provides a filter to views that filters out nodes that have or have not nodes that are referenced to ohter nodes
 */

function nodereference_filters_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'nodereference_filters') . '/views/handlers',
    ),
    'handlers' => array(
      'nodereference_filters_handler_filter_ref' => array(
        'parent' => 'views_handler_filter_in_operator',
        'file' => 'nodereference_filters_handler_filter_ref.inc',
      ),
    ),
  );
}
function nodereference_filters_views_data_alter(&$data) {
  $data['node']['nodereference_filters'] = array(
    'title' => t('Nodereference filters'),
    'help' => t('Filter out nodes that have or have not any node references'),
    'filter' => array(
      'handler' => 'nodereference_filters_handler_filter_ref',
      'label' => t('Nodereference filters'),
    ),
  );
}