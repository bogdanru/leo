<?php
/**
 * @file
 * treaty.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function treaty_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ecolex|node|treaty|form';
  $field_group->group_name = 'group_ecolex';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'treaty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_treaty_field_group';
  $field_group->data = array(
    'label' => 'Ecolex',
    'weight' => '20',
    'children' => array(
      0 => 'field_abstract',
      1 => 'field_alternative_record_id',
      2 => 'field_available_in',
      3 => 'field_cited_treaties',
      4 => 'field_date_of_text',
      5 => 'field_depositary',
      6 => 'field_ecolex_glossary',
      7 => 'field_ecolex_url',
      8 => 'field_field_of_application',
      9 => 'field_internet_reference',
      10 => 'field_jurisdiction',
      11 => 'field_number_of_pages',
      12 => 'field_obsolete',
      13 => 'field_original_record_id',
      14 => 'field_place_of_adoption',
      15 => 'field_related_website',
      16 => 'field_type_of_text',
      17 => 'field_ecolex_tags',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_ecolex|node|treaty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_links|node|treaty|form';
  $field_group->group_name = 'group_external_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'treaty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_treaty_field_group';
  $field_group->data = array(
    'label' => 'External links',
    'weight' => '18',
    'children' => array(
      0 => 'field_faolex_url',
      1 => 'field_treaty_parties_url',
      2 => 'field_treaty_text_url',
      3 => 'field_treaty_website_url',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_external_links|node|treaty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_technical_data|node|treaty|form';
  $field_group->group_name = 'group_technical_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'treaty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_treaty_field_group';
  $field_group->data = array(
    'label' => 'Technical data',
    'weight' => '21',
    'children' => array(
      0 => 'field_odata_identifier',
      1 => 'field_ratification_xml_url',
      2 => 'field_sorting_order',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-technical-data field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_technical_data|node|treaty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_treaty_field_group|node|treaty|form';
  $field_group->group_name = 'group_treaty_field_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'treaty';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '21',
    'children' => array(
      0 => 'group_ecolex',
      1 => 'group_external_links',
      2 => 'group_technical_data',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Additional information',
      'instance_settings' => array(
        'classes' => 'group-treaty-field-group field-group-htabs',
      ),
    ),
  );
  $export['group_treaty_field_group|node|treaty|form'] = $field_group;

  return $export;
}
