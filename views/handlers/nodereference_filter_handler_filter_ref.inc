<?php

class nodereference_filter_handler_filter_ref extends views_handler_filter_in_operator {
  /**
   * Constructor implementation
   lo */
  function construct() {
    parent::construct();
  }

  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();
    foreach (content_fields() as $key => $field) {
      if ($field['type'] == 'nodereference') {
        $this->value_options[$key] = $key;
      }
    }
  }

  function operators() {
    $operators = array(
      'in' => array(
        'title' => t('Has references'),
        'short' => t('in'),
        'short_single' => t('='),
        'method' => 'op_noderef',
        'values' => 1,
      ),
      'not in' => array(
        'title' => t('Has No references'),
        'short' => t('not in'),
        'short_single' => t('<>'),
        'method' => 'op_noderef',
        'values' => 1,
      ),
    );
    return $operators;
  }

  function op_noderef() {
    if (empty($this->value)) {
      return;
    }
    $this->ensure_my_table();

    foreach ($this->value as $field) {
      $field_info = content_fields($field);
      $db_info = content_database_info($field_info);
      $query = "(SELECT {$db_info['columns']['nid']['column']} FROM {{$db_info['table']}})";
      $this->query->add_where($this->options['group'], "$this->table_alias.nid " . $this->operator . $query);
    }   
  }
}