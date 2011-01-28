<?php

function nodereference_filter_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'nodereference_filter') . '/views/handlers',
    ),
    'handlers' => array(
      'nodereference_filter_handler_filter_ref' => array(
        'parent' => 'views_handler_filter_in_operator',
        'file' => 'nodereference_filter_handler_filter_ref.inc',
      ),
    ),
  );
}
function nodereference_filter_views_data_alter(&$data) {
  $data['node']['nodereference_filter'] = array(
    'title' => t('Nodereference filter'),
    'help' => t('Filter out nodes that have or have not any node references'),
    'filter' => array(
      'handler' => 'nodereference_filter_handler_filter_ref',
      'label' => t('Nodereference filter'),
    ),
  );
}