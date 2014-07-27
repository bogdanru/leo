<?php

class MigrateTreaties extends DynamicMigration {

  public function __construct($arguments) {
    parent::__construct();

    $this->description = 'Import InforMEA treaties';
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array('type' => 'int',
          'length' => 2,
          'not null' => TRUE,
          'description' => 'Source PK',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('default', 'for_migration')
      ->select('ai_treaty', 't')
      ->fields('t');


    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationNode('treaty');

    $this->addFieldMapping('title_field', 'short_title');
    $this->addFieldMapping('title', 'short_title');
    $this->addFieldMapping('field_treaty_long_name', 'long_title');
    $this->addFieldMapping('body', 'abstract');
    $this->addFieldMapping('body:language')->defaultValue('en');
    $this->addFieldMapping('field_treaty_primary', 'primary');
    $this->addFieldMapping('field_enter_into_force', 'start');
    $this->addFieldMapping('field_url_treaty_text', 'url_treaty_text');
    $this->addFieldMapping('field_url_treaty_website', 'url');
    $this->addFieldMapping('field_url_treaty_parties', 'url_parties');
    $this->addFieldMapping('field_number_of_parties', 'number_of_parties');
    $this->addFieldMapping('field_sorting_order', 'order');
    $this->addFieldMapping('field_treaty_is_protocol', 'is_protocol');
    // $this->addFieldMapping('', 'logo_medium');
    $this->addFieldMapping('field_odata_identifier', 'odata_name');
    $this->addFieldMapping('field_ratification_xml_url', 'ratification_xml_url');
    $this->addFieldMapping('field_logo', 'logo_medium');

    #$this->addFieldMapping('created', 'rec_created');
    $this->addFieldMapping('uid')->defaultValue(1);
  }

  function prepareRow($row) {
    $row->logo_medium = '/Work/informea/www.old/wp-content/uploads/' . $row->logo_medium;
    return TRUE;
  }
  protected function generateMachineName() {
    return 'Treaties';
  }
}